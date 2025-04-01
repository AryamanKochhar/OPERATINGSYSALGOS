//the logic for the producer 
// The producer should produce data only when the buffer is not full. In case it is found that the buffer is full, the producer is not allowed to store any data into the memory buffer.
// Data can only be consumed by the consumer if and only if the memory buffer is not empty. In case it is found that the buffer is empty, the consumer is not allowed to use any data from the memory buffer.
// Accessing memory buffer should not be allowed to producer and consumer at the same time.
//producer code
int count=0; 
wait( S )  
{  
while( S <= 0) ;  //runs till the () ->false
S--;  
}  
signal( S )  
{  
S++;  
}  
void producer(void){
    wait(empty);
    wait(s);//"S" is a binary semaphore BUFFER
    produceitem(pitem)
    buffer[in]=pitem;//in is the place where the next empty place is there
    in=(in+1)%n;//increment the index of the next empty place
    signal(s);
    signal(full);//counting sema which no of full buffers
  
}
void consumer(void){
  
    wait(full);
    wait(s); 
    citem=buffer[out];
    out=(out+1)%n;//increment the index of the next empty place
    signal(s);
    signal(empty)


}