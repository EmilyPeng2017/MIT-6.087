Problem 4.1
Consider the insertion sort algorithm described in Lecture 5 In this problem, you will re-implement
the algorithm using pointers and pointer arithmetic.
(a) The function shift element() takes as input the index of an array element that has been
determined to be out of order. The function shifts the element towards the front of the array,
repeatedly swapping the preceding element until the out-of-order element is in the proper
location. The implementation using array indexing is provided below for your reference:
/∗ move pr evi ous e l ement s down u n ti l
i n s e r ti o n point reached ∗/
void s h i ft e l e m e n t (unsigned int i ) {
int i v a l u e ;
/∗ guard a g a ins t going out s ide ar ray ∗/
for ( i v a l u e = a r r [ i ] ; i && a r r [ i −1] > i v a l u e ; i −−)
a r r [ i ] = a r r [ i −1]; /∗ move element down ∗/
a r r [ i ] = i v a l u e ; /∗ i n s e r t element ∗/
}
Re-implement this function using pointers and pointer arithmetic instead of array indexing.
/∗ i n t ∗pElement − po int e r to the element
in a r r ( type i n t [ ] ) that i s out−of−pl a c e ∗/
void s h i ft e l e m e n t ( int ∗pElement) {
/∗ i n s e r t code he r e ∗/
}
