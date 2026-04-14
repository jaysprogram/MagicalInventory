# MagicalInventory

A C program for practicing arrays and dynamic memory allocation, built around a magical inventory management problem hello world

## Description

The program reads a set of roles, each requiring specific amounts of named magical materials. It then assigns roles to denizens, tracks the total amount of each material needed across all denizens, and calculates the total magic required (material amount × magic cost per material). After the initial calculation, it processes a series of updates:

- **Type 1 update** – Change the magic requirement of a named material to a new value.
- **Type 2 update** – Change the amount of a specific material required by a given role.

After each update, the program prints the new total magic required.

Internally, the program uses dynamically allocated arrays for both the role list and the materials list. The materials list grows automatically via `realloc` when capacity is exceeded. Memory is freed at program exit.

## Tech Stack

- C (`stdio.h`, `stdlib.h`, `string.h`)

## Input Format

Input is read from stdin. The sample files (`input.txt`, `input1.txt`, `input`) illustrate the expected format:

1. Number of roles
2. For each role: number of distinct materials followed by `<material_name> <amount>` pairs
3. For each material (in the order first encountered): `<material_name> <magic_cost>`
4. Number of denizens, followed by a role index (1-based) for each denizen
5. Number of updates, followed by update lines of the form:
   - `1 <material_name> <new_magic_cost>`
   - `2 <role_index> <material_name> <new_amount>`

## Usage

Compile and run with an input file redirected to stdin:

```sh
gcc main.c -o magical_inventory
./magical_inventory < input.txt
```