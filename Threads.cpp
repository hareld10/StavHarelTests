//
// Created by mstav on 4/29/18.
//
#include <vector>

#include "Threads.h"


/**
 * Constructor
 */
Threads::Threads() {
    _ready_threads = new std::vector<Thread*>;
    _blocked_threads = new std::vector<Thread*>;
}

/**
 *  Destructor
 */
Threads::~Threads() {
    // Delete the ready threads vector:
    for (Thread* t:(*_ready_threads)){
        delete t;
    }
    delete _ready_threads;
    _running_thread = nullptr;

    // Delete the blocked threads vector:
    for (Thread* t:(*_blocked_threads)){
        delete t;
    }
    delete _blocked_threads;

    //todo if we allocated this instance with "new"- add "delete this"
}


void Threads::add_ready(Thread *thread) {
    _ready_threads->push_back(thread);

}

void Threads::add_blocked(Thread *thread) {
    _blocked_threads->push_back(thread);

}

int Threads::remove_blocked_thread(int id)
{
    auto iter = _blocked_threads->begin();
    for( ; iter != _blocked_threads->end(); ++iter)
    {
        if ((*iter)->id == id)
        {
            Thread* temp = *iter;
            _blocked_threads->erase(iter);
            delete(temp);
            return EXIT_SUCCESS;
        }
    }
    // Thread not found:
    return FAIL_CODE;
}


int Threads::remove_ready_thread(int id) {
    auto iter = _ready_threads->begin();
    for( ; iter != _ready_threads->end(); ++iter)
    {
        if ((*iter)->id == id)
        {
            Thread* temp = *iter;
            _ready_threads->erase(iter);
            delete(temp);
            return EXIT_SUCCESS;
        }
    }
    // Thread not found:
    return FAIL_CODE;
}

/**
 * Removes the thread from its' vector and returns it.
 * @param tid id of wanted thread.
 * @return wanted thread if exists, nullptr o.w..
 */
Thread *Threads::get_thread(int tid) {
    auto iter = _blocked_threads->begin();
    for( ; iter != _blocked_threads->end(); ++iter)
    {
        // Found thread, add it to the ready list:
        if ((*iter)->id == tid)
        {
            Thread* temp = *iter;
            _blocked_threads->erase(iter);
            return temp;
        }
    }
    iter = _ready_threads->begin();
    for( ; iter != _ready_threads->end(); ++iter)
    {
        // Found thread, add it to the ready list:
        if ((*iter)->id == tid)
        {
            Thread* temp = *iter;
            _ready_threads->erase(iter);
            return temp;
        }
    }
    // Thread not found:
    return nullptr;
}





bool Threads::exist_by_id_ready(int id) {
    for(Thread* i: *_ready_threads){
        if(i->id == id){
            return true;
        }
    }
    return false;
}

int Threads::running_thread_id(){
    if (_running_thread == nullptr){
        std::cout << "Returned nullptr from running_thred_id";
        return -1;
    }
    return _running_thread->id;
}

bool Threads::exist_by_id_blocked(int id) {
    for(Thread* i: *_blocked_threads){
        if(i->id == id){
            return true;
        }
    }
    return false;
}