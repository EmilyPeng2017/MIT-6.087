




Problem 2.3
Consider int val=0xCAFE; Write expressions using bitwise operators that do the following:
• test if atleast three of last four bits (LSB) are on
• reverse the byte order (i.e., produce val=0xFECA)
• rotate fourbits (i.e., produce val=0xECAF)
1. (val&0XF)|(val&0X7)|(val&0XB)|(val&0XD)|(val&0XE)
2. (val&0XFF<<8)|(val&0XFF00>>8)
3. (val&0XF<<12)|(val>>4)

Problem 2.4
Using precedence rules, evaluate the following expressions and determine the value of the variables(without running the code). Also rewrite them using parenthesis to make the order explicit.
• Assume (x=0xFF33,MASK=0xFF00).Expression: c=x & MASK ==0;
• Assume (x=10,y=2,z=2;).Expression: z=y=x++ + ++y∗2;
• Assume (x=10,y=4,z=1;).Expression: y>>= x&0x2 && z
1. c = 0xFF
2. x=11, z=16, y=17
3. 

Problem 2.5
Determine if the following statements have any errors. If so, highlight them and explain why.
• int 2nd_value=10;
• Assume (x=0,y=0,alliszero=1). alliszero =(x=1) && (y=0);
• Assume (x=10,y=3,z=0;). y=++x+y;z=z−−>x;
• Assume that we want to test if last four bits of x are on. (int MASK=0xF;ison=x&MASK==MASK)

1. number can not be the first character.
2. alliszero = (x==1) && (y==0)
3. correct
4. ison = (x&MASK)==MASK
