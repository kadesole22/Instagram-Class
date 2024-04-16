#ifndef INSTAGRAM_H
#define INSTAGRAM_H
#include "stack.h"

template <typename T>
class instagram {
private:
    int numFollowers;
    T user;
    Stack<T> followerList;

public:
    instagram() : numFollowers(0) {}

    void addFollower(T user) {
        followerList.push(user);
        numFollowers++;
    }

    T removeFollower() {
        if (!followerList.isEmpty()) {
            T removedFollower = followerList.pop();
            numFollowers--;
            return removedFollower;
        }
        // Handle case where followerList is empty
    }

    void printFollowers() {
        followerList.print();
    }

    T latestFollower() {
        if (!followerList.isEmpty()) {
            return followerList.peek();
        }
        // Handle case where followerList is empty
    }

    void resetFollowers() {
        followerList.makeEmpty();
        numFollowers = 0;
    }

    bool checklist() {
        return followerList.isEmpty();
    }
};

#endif /* INSTAGRAM_H */
