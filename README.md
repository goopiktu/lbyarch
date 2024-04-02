![image](https://github.com/goopiktu/lbyarch/assets/91401877/640818a7-7c17-4f9f-a17a-45da0e8920aa)

![image](https://github.com/goopiktu/lbyarch/assets/91401877/0d1c6ffd-ebd6-472d-911b-bee62fcd89a8)

![image](https://github.com/goopiktu/lbyarch/assets/91401877/59804a9e-3520-4754-9bb2-e3679e8bc8c6)
The input of the elements for the vector is 1,048,576(2^20) 16,777,216(2^24) and [1,073,741,824(2^30)] or [268,435,456 2^28] or [536,870,912 2^30]


We noticed that in debug mode, C was slower than the assembly time 
we made the C program first to see if our assembly was correct. We did this by separating the output of the c function and the assembly function so that it wouldn't write into the same array, And we also made it so that both the functions receive the same input


As for release mode, unfortunately, the assembly wasn't working. and we couldn't figure out how to fix it but with the timing given the same vertex size with debug mode. We were able to conclude that the assembly was slower. Even if there was no correct output for release We assumed that it was the same as debug it's just that some of the addresses are not correctly accessed when it comes to release mode.
![image](https://github.com/goopiktu/lbyarch/assets/91401877/24a20dce-358a-4e39-a6c1-2a615bfea641)


![image](https://github.com/goopiktu/lbyarch/assets/91401877/4256d465-765c-4981-8309-98378df6fc60)


![image](https://github.com/goopiktu/lbyarch/assets/91401877/a58a4a8e-f6fc-45cc-bf35-9753ebae72be)


We concluded that since release mode optimizes the code of c. That is the reason why it's quicker than assembly. But for debug it doesn't optimize it for you, thats why assembly is so much quicker compared to the purely c program.
