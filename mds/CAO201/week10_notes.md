Inter Process Comms and Scheduling
==================================

Processes: can they speak to eachother? Who goes first when they're both top dog?

Models of process scheduling
----------------------------

Scheduling is a way of achieving an outcome. First you need a **metric** by which it will be measured. One starting metric is **turnaround**. Simply put, how much time elapsed between the jobs arrival and its completion?

$Tturnaround = Tcompletion - Tarrival$

This measures **performance**. There are other metrics we might prefer depending on the use case. One is **fairness**. Often performance comes at the cost of fairness, and vice versa.

### FIFO: First in, First out.
If you arrive first, you run to completion. This is the post office, bank and doctors waiting room model.

### SJF
Shortest job first, so we're not all waiting for the guy who can't choose what he wants then gets angry they don't have american express. 

The teller could ask the 3 customers who arrive together how long their taks are, then serve the shortest first.

But if they walk in slightly after each other? Long job guy might have walked in 30 seconds before quick question guy, and now quick question guy has to wait a half hour. Windows?

### STCF

The problem here is that clients, once engaged with the teller, can't be interrupted. The arriving processes are allowed to run to completion. 

What if we can **preempt slow guy**: "Sir, we're well on track, let me just answer this man's one question."

Quick guy's deal with, sent on his way, and slow guy's job continues. This improves average turnaround. 

Responsiveness
--------------

These policy changes improve **average turnaround times**. 
* Suitable for drop off and pick up jobs, as with early batch computing.
* Not so good for response time: waiting in line is not how a terminal needs to feel.
  
Enter **time sharing and multiple users** with interfaces. 

A new metric asks, how long does it take a new process to get system attention?

**$Tresponse = Tfirstrun - Tarrival$**.

Round Robin
-----------

Serve each process for a slice of time: 1ms, 10ms?

* The peak of fairness and response time
* Performance killing context switches
* Target: time slice long enough to minimise switches but preserve responsiveness

Mutual Exclusion
-----------------
With so many processes and threads pushing for time and grabbing for resources, how do we enforce order? A computer has to be predictable.

When two people want an unsharable resource we have.. **conflict!** So it goes with threads. 

Here's a dramatic reinterpretation of Navin Ipe's [outdated phonebooth metaphor](http://nrecursions.blogspot.com/2014/08/mutex-tutorial-and-example.html).

Say you're at a nightclub at 2am and **your bowels want to move**. You head to the toilet, you wait 35 minutes, and **you get a cubicle**. Once inside you discover.. **no lock!** It's sort of hanging off one screw and you can't fix it. The only option is to sit, take care of business, and **stick your foot against the door**. Every 8-10 seconds someone staggers by and **tries to push it open**, but the **bones of your leg win each time**. When you're done, you take **your foot off the door**, leave and the cubicle and the **next person enters**!
_
The **threads** are: _you and each staggerer_
The **mutex** is: _the door_
The **lock** is: _your leg/foot_
The **resource** is: _the throne_.

Any thread wanting to **run a few lines of code that can't be interrupted** without a disaster (a person in the middle of moving their bowel) has to **place a lock** (straightens a leg, foot extended) on **a mutex** (against the door).


```C
 #include <iostream>
#include <thread>
#include <mutex>

std::mutex door;//you can use std::lock_guard if you want to be exception safe 
int i = 0; 
void moveYourBowel() 
{

    // You enter the cubicle and extend your leg 
    door.lock();    // Your foot presses against the door 
                    // You go about your planned activity privately
      
      std::cout << i << "COUGH cough" << std::endl;
      i++;                  // You complete your atomic action without
                            // interruption, having secured the resource
    door.unlock();          // You lower your leg and exit, freeing
                            // the resource 
}

int main() 
{
    // You are on the dance floor with many patrons.

    // You leave the crowd to ease a burden
    std::thread dancer(moveYourBowel);
    
    // Another dancer lurches from the dance floor, 
    // making straight for the loos.
    std::thread staggerer1(moveYourBowel);
    
    //And hey, man3 also joined the race to the booth
    std::thread staggerer2(moveYourBowel);

    dancer.join();          //Finished, you rejoin the crowd.
    staggerer1.join();      // Staggerer1 returns to his bad dancing.
    staggerer2.join();      // So does 2.
    return 0;
}

``` 

Compile and run it using  

g++ -std=c++0x -pthread -o thread thread.cpp

./thread 



Kernel Space and User Space