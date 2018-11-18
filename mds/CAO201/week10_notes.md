Inter Process Comms and Scheduling
==================================

Processes: can they speak to eachother? Who goes first when they're both top dog?

Models of process scheduling
----------------------------

### FIFO: First in, First out.
If you arrive first, you run to completion. This is the post office, bank and doctors waiting room model.

### SJF
Shortest job first, so we're not all waiting for the guy who can't choose what he wants then gets angry they don't have american express.

Windows?

Mutual Exclusion
-----------------
When two people want single, unsharable resource we have.. conflict! So it goes with threads. Here's a dramatic reinterpretation of Navin Ipe's [outdated phonebooth metaphor](http://nrecursions.blogspot.com/2014/08/mutex-tutorial-and-example.html).

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