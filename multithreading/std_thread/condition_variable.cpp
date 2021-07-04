#include <cassert>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>

#define M_MAX_FRAME_NUM 5

using DValueType = int;
struct MParam
{
    short frameReady[M_MAX_FRAME_NUM];

    int arrSz;
    int nframes;
    MParam(const int _arrsz, const int _nframes) : arrSz(_arrsz), nframes(_nframes)
    {
        memset(frameReady, 0, sizeof(short) * M_MAX_FRAME_NUM);
    }

    MParam() : MParam(int(1e8), 0)
    {
        // new (this)MParam(100, 0);
    }
};

struct MBuffer
{
    bool ready;
    int some[2];
    DValueType *data;
    MBuffer()
    {
        ready = false;
        data  = nullptr;
    }
    ~MBuffer()
    {
        if (data)
            delete[] data;
        data = nullptr;
        printf("~MBuffer()\n");
    }
};


std::condition_variable condv;
std::mutex mtx;
std::vector<bool> preparedFalgs(4, false);

bool isPrepared(int index) { return (preparedFalgs[index]); }

bool isPrepared(MParam &para, int index)
{
    printf("frameReady[%d]= %d\n", para.frameReady[index]); // abnormal values
    return (para.frameReady[index] > 0);
}


void prepareData(MBuffer *buffers, MParam &para, int index)
{
    assert(index < para.nframes);

    printf("%s(): prepare data for index= %d\n", __FUNCTION__, index);
    std::lock_guard<std::mutex> lkGaurd(mtx);
    buffers[index].data  = new DValueType[para.arrSz];
    buffers[index].ready = true;

    for (int i = 0; i < para.arrSz; i++)
    {
        buffers[index].data[i] = index * i;
    }
    para.frameReady[index] = 1;
    preparedFalgs[index]   = true;
    printf("%s(): data prepared index= %d\n", __FUNCTION__, index);
    condv.notify_one();
}

void prepareDataX(MBuffer *buffers, MParam &para)
{
    for (int i = 0; i < para.nframes; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        prepareData(buffers, para, i);
    }
}

void processData(MBuffer *buffers, MParam &para, int index)
{
    assert(index < para.nframes);
    assert(buffers);
    printf("%s(): process data index= %d, wait...\n", __FUNCTION__, index);
    std::unique_lock<std::mutex> mlock(mtx);
    while (!isPrepared(index))
        // while(!isPrepared(para, index))  // needs to be global? else seems to fail
        condv.wait(mlock);

    if (preparedFalgs[index])
    // if (para.frameReady[index])
    {
        for (int i = 0; i < para.arrSz; i++)
        {
            if (i < 100)
                printf("%d ", buffers[index].data[i]);
        }
        printf("\n%s(): process finished index= %d\n", __FUNCTION__, index);
    }
}

int main(const int argc, const char *argv[])
{
    MParam param;
    constexpr int nframes = 4;
    param.nframes         = nframes;
    MBuffer buffers[nframes];

    std::vector<std::thread> threads;
    for (int i = 0; i < nframes; i++)
    {
        threads.push_back(std::thread(processData, buffers, param, i));
    }

    for (int i = 0; i < nframes; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        prepareData(buffers, param, i);
    }
    // std::thread t1(prepareDataX, buffers, param);
    // printf("%s(): t1.id= %d\n", __FUNCTION__, t1.get_id());
    printf("%s(): main-thread.id= %d\n", __FUNCTION__, std::this_thread::get_id());


    for (auto &e : threads)
        e.join();

    // t1.join();

    return 0;
}