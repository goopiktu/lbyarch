![image](https://github.com/goopiktu/lbyarch/assets/91401877/b1012963-918f-4022-93d5-17e9a30546d5)

![image](https://github.com/goopiktu/lbyarch/assets/91401877/8aedd15a-4d97-418f-9563-9b65f076eeb5)

![image](https://github.com/goopiktu/lbyarch/assets/91401877/23231c50-3d7a-4694-b151-a7eecf4a1b5c)


Based on our required inputs we were not able to get the times for them so we had to increase the size of the array to be able to see the difference. The input of the elements for the vector is 

So we used the size 200,000 240,000 and 300,000
![image](https://github.com/goopiktu/lbyarch/assets/91401877/b31b8e5d-c810-45d6-9a65-979c2de5a1be)

![image](https://github.com/goopiktu/lbyarch/assets/91401877/9b3b92b8-83a5-4255-9c65-a565c3ca2d1d)

![image](https://github.com/goopiktu/lbyarch/assets/91401877/148e9bf9-899e-4bcf-a7da-80de2986b934)

We noticed that in debug mode, C was slower than the assembly time 
we made the C program first to see if our assembly was correct. We did this by separating the output of the c function and the assembly function so that it wouldn't write into the same array, And we also made it so that both the functions receive the same input


As for release mode, unfortunately, the assembly wasn't working. and we couldn't figure out how to fix it but with the timing given the same vertex size with debug mode. We were able to conclude that the assembly was slower. Even if there was no correct output for release We assumed that it was the same as debug it's just that some of the addresses are not correctly accessed when it comes to release mode.
![image](https://github.com/goopiktu/lbyarch/assets/91401877/f0b9ce65-8dcd-4a87-9b32-a38ec26f051d)

![image](https://github.com/goopiktu/lbyarch/assets/91401877/51b01d18-147a-44ef-acfe-354920e69552)

![image](https://github.com/goopiktu/lbyarch/assets/91401877/402765b6-d8cb-42d7-9ff6-5743166fd15a)

We concluded that since release mode optimizes the code of c. That is the reason why it's quicker than assembly. But for debug it doesn't optimize it for you, thats why assembly is so much quicker compared to the purely c program.
