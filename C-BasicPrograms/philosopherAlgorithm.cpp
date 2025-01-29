#include <iostream>
#include <thread>
#include <semaphore.h>
#include <vector>
#include <chrono>

using namespace std;

// Number of philosophers
const int NUM_PHILOSOPHERS = 5;

// Semaphores for forks
sem_t forks[NUM_PHILOSOPHERS];

void philosopher(int philosopher_id) {
    while (true) {
        // Thinking
        cout << "Philosopher " << philosopher_id << " is thinking." << endl;
        this_thread::sleep_for(chrono::seconds(1));

        // Picking up forks
        int left_fork = philosopher_id;
        int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

        // Prevent deadlock: odd philosophers pick left first, even pick right first
        if (philosopher_id % 2 == 0) {
            sem_wait(&forks[left_fork]);  // Acquire left fork
            sem_wait(&forks[right_fork]); // Acquire right fork
        } else {
            sem_wait(&forks[right_fork]); // Acquire right fork
            sem_wait(&forks[left_fork]);  // Acquire left fork
        }

        // Eating
        cout << "Philosopher " << philosopher_id << " is eating." << endl;
        this_thread::sleep_for(chrono::seconds(2));

        // Releasing forks
        sem_post(&forks[left_fork]);  // Release left fork
        sem_post(&forks[right_fork]); // Release right fork

        cout << "Philosopher " << philosopher_id << " finished eating and put down forks." << endl;
    }
}

int main() {
    // Initialize semaphores for forks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    vector<thread> philosophers;
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosophers.emplace_back(philosopher, i);
    }

    // Join threads (optional, as this program runs indefinitely)
    for (auto& t : philosophers) {
        t.join();
    }

    // Destroy semaphores (not reached in this program)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
