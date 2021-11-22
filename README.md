# Bonus_Project_AL
# Project: pde-solver

Idea contributed by Stian Howard (ge96leb@tum.de) Moritz Meyer (Mo.Meyer@tum.de).

## Motivation

Many physical phenoma, such as heat flow and fluid dynamics to name two examples, are able to be described through partial differential equations. 
Subsequently, being able to solve these systems for real scenarios is a task of interest. 
This interest can be in both the transient, that is the time development of the sytem, as well as the steady-state, or end-state, solutions. 
For this project, you will be looking at the steady-state solutions for the 2D heat equation.

## Sprint 1

In this sprint, you will be implementing a basic PDE solver with a simple mesh. 
There will be some unit tests written to allow more efficient code editing later. 

### Definition of "done"

- The project contains a comprehensive `README.md` file explaining how to use it, including an example.
- The project outputs the steady-state values of each node in a result file. (This is intentionally vague on output format to allow different implentations of node-identification, coordinate systems, etc.)
- The project contains at least one unit test which compares one simple case with a coresponding analytical solution.

## Sprint 2

In this sprint, you will be implementing the core functionality of the program through logical use of classes. 
Additionally, the functionality can be extended, for example, by allowing an additional coordinate system (e.g. polar), allowing additional relaxation schemes (e.g. Jacobian vs. Gauss-Seidel), or employing boundary conditions as 'boundary node' objects in the mesh to allow more complex scenarios, etc. 

### Definition of "done"

- The user can select what mesh to solve, with the program pulling options from a directory.
- If additional functionality is added to the program, which requires user input, the input is done in a logical, user-friendly manner.
- The `README.md` file should explain how one could extend the code to include a new feature.

## Sprint 3

In this sprint, you need to study and improve the performance of your code.
Select at least three different scenarios to investigate the performance of your code.
Find potential performance bottlenecks (e.g. using a profiler such as gprof) and investigate optimization options for your code, including loop transformations, STL containers and algorithms, and vectorization options. You may also try other parallelization techniques, if you already know of any, but we encourage you to focus on the elements discussed in the lecture.

### Definition of "done"

- A file `performance.md` presents your observations from the performance analysis.
- The same file presents at least three different optimization techniques you applied, with the performance effects you observed.
- The final code should include the (in your conclusion) most optimized version of your code. 

