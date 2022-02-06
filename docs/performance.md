The most time was spent in the steady-state solver (according to the gprof). In my future comments on the steady_state.cpp I suggest some improvements in this part. 
100x100 grid with 5000 iteration and 0.0001 was run for this test.   
Hence efforsts were put to make this part faster  

## Optimtization 1
error was being calculated twice in residual loop. Giving a variable to new error helped in around 7% decrease in run time.  
giving a constant variable for (k*dx*dy) gave a boost of around 8% decrease in run time.  

## Optimization 2
deleted variables solution     
error term now calculated at every 5th iteration    
These changes caused a 30% reduction in time    

## Optimization 3
Without optimization 2, compareing compiler flag with no flag gave us:  
compiler flag -O1 gave a performance of 84% decrease in run time.  
compiler flag -O2 gave a performance of 85% decrease in run time.  
compiler flag -O3 gave a performance of 87% decrease in run time.  

## Otimization 4
Combining optimization 2 with -O3 flags we see an additional 30% reduction in time due to error term now being calculated every 5th iteration.
