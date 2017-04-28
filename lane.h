#ifndef STRUCTURES_LANE_H
#define STRUCTURES_LANE_H

#include<cstdint>
#include<stdexcept>

#include "linked_queue.h"
#include "linked_list.h"

namespace structures {

template<typename T>


class Lane {
public:
    Lane() = default;

    ~Lane(){}

    /*! Lane Change
    *
    * Vehicle arrives at semaphore and decides which lane it will change to */
    void lane_change() {

    }

    void insert_vehicle() {

    }

    int speed_limit() {
        return speed_limit_;
    }

    std::size_t size() const {
        return size_;
    }

protected:
    structures::LinkedList<int> list{};  //Probably not int. It's temporary.

private:
    int speed_limit_;
    std::size_t size_;
    structures::LinkedList<Lane> lanes{};  // Possible destinations


    class Vehicle{
    public:
        Vehicle (const int& length):
        length_{length}
        {}

        ~Vehicle(){}  // Destructor

    /*Space
    *
    *@brief: Space ocuppied by a Vehicle.
    *
    *Determined by the vehicle's length + 1m ahead and 2m behind it. */
        int& space() {
            auto space_ = length() + 3;  // Needs proper implementing
            return space_;
        }

        int& length() {
            return length_;
        }

        const int& length() const {
            return length_;
        }

        Vehicle* next(){
            return next_;
        }

        const Vehicle* next() const {
            return next_;
        }

        void next(Vehicle* vehicle) {
            next_ = vehicle;
        }

    private:
        int length_;
        Vehicle *next_{nullptr};

    };

    Vehicle* end () {
        auto n = head;

        for (auto i = 1u; i < size(); ++i) {
            n = n->next();
        }
        return n;
    }

    Vehicle* head{nullptr};

};

}  // namespace structures

#endif
