wait(x){
  while(x<=0);
  x--;
}
signal(x){
  x++;
}
// we use a semaphore to represent a chopstick and this truly acts as a solution of the Dining Philosophers Problem. Wait and Signal operations will be used for the solution of the Dining Philosophers Problem, for picking a chopstick wait operation can be executed while for releasing a chopstick signal semaphore can be executed.
void phy(void){
  wait(a[x]);//taking chopstick
  wait(a[(x+1)%5]); //assuming there are 5 philosphers sitting so  there are 5+1 chopsticks and only opposite can use one 
  EATING(BIRYANI);

  signal(a[x]); //freeing up the used chopstick
  signal(a[x+1]%5);
  THINKING(ABOUT_BIRYANI);

  
}