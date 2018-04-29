//
// Created by hareld10 on 4/29/18.
//

#ifndef OSEX2_SCHEDULER_H
#define OSEX2_SCHEDULER_H


#include <vector>
#include <queue>
#include "Thread.h"
#include "Threads.h"

class Scheduler
{

public:
    static int total_num_of_threads;
    static Threads my_threads;
    static std::priority_queue<int, std::vector<int>,  std::less<int>> pq;

    // stav needs to call that
    static void init();
    static int get_next_id();
    static void insert_id(int _id);

    static void add_ready(Thread *thread);
    static void add_blocked(Thread *thread);

    static bool exist_by_id_ready(int id);
    static bool exist_by_id_blocked(int id);
    static int running_thred_id();
};

#endif //OSEX2_SCHEDULER_H
