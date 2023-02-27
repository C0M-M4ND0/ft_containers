# ft_containers
Implementation  of a few c++ container using c++98

   see the ``en.subject.pdf``
   
![1_zwYif2fwfrRmqonno8hHGQ](https://user-images.githubusercontent.com/94039533/221577488-9eb2b605-aa04-42c3-80d8-4c42e1913dbe.png)

### Final grade : 125/100

Mandatory part : 100/100

Bonus : 25/25

### Description
   This repository contains a C++ implementation of several commonly used STL containers, including vector, stack, map, and set.
  The implementation is written in C++98 and is intended to be compatible with older compilers.
  
   Each container is implemented as a separate class, with a similar interface to the corresponding
  STL container including the iteartor to each container that need an iterator ...
  
   The containers are implemented using templates, so they can store any type of object. However,
  there are some limitations on the types that can be stored, such as restrictions on copy constructors and assignment operators.
  
   This implementation is intended to be a learning resource for those who want to understand how the STL containers work under the hood,
  as well as a reference for those who need to use a subset of the containers in an older codebase.
  
   The set and map containers are implemented using a Red-Black Tree.  the Red-Black Tree implementation is included in the ``red-black_tree.hpp`` header file,
  and is used by the set and map containers to maintain their order and perform fast lookups. The tree is balanced and self-adjusting, 
  ensuring efficient operations even for large datasets.
  
### Test
  The implementation has been tested using the ft_containers-unit-test, which can be found at https://github.com/divinepet/ft_containers-unit-test. 
  The tests cover a wide range of scenarios and edge cases, and are designed to ensure that the containers behave correctly and efficiently.
  
  In addition to the unit tests, I have included some additional tests in the ``tests`` directory. These tests cover some additional scenarios and edge cases, and can be run using make and the appropriate command line arguments. The available tests are:<br>
   main -v: Runs tests for the vector container.<br>
   main -st: Runs tests for the stack container.<br>
   main -s: Runs tests for the set container.<br>
   main -m: Runs tests for the map container.<br>
   Optional [-fast] argument can be added to run a fast version of the tests.<br>
   ##### Don't forget to report to me the Errors in the project and also your suggestions about it .... to make it better 😉
   <a href="https://github.com/C0M-M4ND0" target="_blank"><img src="https://img.shields.io/badge/github-000000?style=flat-square&logo=Github&logoColor=white"/></a>
   [![Gmail Badge](https://img.shields.io/badge/-Gmail-d14836?style=flat-square&logo=Gmail&logoColor=white&link=mailto:omarabdelhadi1337@gmail.com)](mailto:omarabdelhadi1337@gmail.com)
   [![Twitter Badge](https://img.shields.io/badge/-Twitter-1c89f0?style=flat-square&logo=twitter&logoColor=white&link=https://twitter.com/C0M_M4ND0/)](https://twitter.com/C0M_M4ND0/)
   [![Facebook Badge](https://img.shields.io/badge/-Facebook-1c89f0?style=flat-square&logo=facebook&logoColor=white&link=https://www.facebook.com/profile.php?id=100086280574052)](https://www.facebook.com/profile.php?id=100086280574052)
