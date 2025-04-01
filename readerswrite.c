wait( S )  
{  
while( S <= 0) ;  
S--;  
}  
  
signal( S )  
{  
S++;  
}  
//mutex and write are semaphores that have an initial value of 1, whereas the readcount variable has an initial value as 0. Both mutex and write are common in reader and writer process code, semaphore mutex ensures mutual exclusion and semaphore write handles the writing mechanism.
void reader(void){
static int readcount = 0;  
wait (mutex);  
readcount ++; // on each entry of reader increment readcount  
if (readcount == 1)  
{  
  wait (write);  
}  
signal(mutex);  
  
//READING THE FILE 
  
wait(mutex);  
readcount --; // on every exit of reader decrement readcount  
if (readcount == 0)  
{  
  signal (write);  
}  
signal(mutex);  
}
void writer(void){
  wait(write);  
//WRITE INTO THE FILE  
signal(write);  
}