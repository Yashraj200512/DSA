# **hasing**

- **let's say we have names of friends in contacts,to make searching easy
  we will assign key to each object,in this case we will use array to store names and ours keys will be integers(index)**

> - if keys are large and cannot be used as index, we will use hashing.
> - hash function converts large keys into small keys.
>> - input values-->[**hash fn**]-->generates keys and map it to values
> - the values are then stored in DS called **Hash table**.
> - the idea of hashing is to distribute entries(key/value pairs) uniformly across an array.

> - each ele is assigned key(converted key gen by hash),by using that key we can access any ele in **O(1)** time
> - using the key,the algorithm(hash fn) computes an index that suggests where an entry can be founded or inserted.

# example
> - if i give values like kurumi,kaguya,teruhashi to hash function then it will generate keys, in hash table,these keys will be indexes(key value depends on algorithm)
>- so output maybe array of size 10 where a[1]=kurumi,a[7]=kaguya etc.