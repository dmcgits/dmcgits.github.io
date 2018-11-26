# Week 9 - Virtual Memory

## Base and Bounds

Assign a starting address and a total size allowance.

> * Base: Beginning address in memory
> 	* The program sees this as zero
>   * It's kept in a register in the CPUs mmu
> * Bounds
>   * How far you can expand

### Linux Time
Exploring a model of a base and bounds

```bash
student:$ cd CAO201/repos/
student:$ ls 
"ostep-code-dmac  ostep-projects-dmac  ostep-python-sims-dmac"

## If you don't find the ostep-python-sims-dmac folder, pull it from git like so:

student:$ git clone https://github.com/DannyMcGillick/ostep-python-sims-dmac.git ostep-python-sims-dmac

## Things download
student:$ cd ostep-python-sims-dmac/module_6
student:$ python3 relocation.py
student:$ python3 relocation.py -a 16k -p 32m

```

Hex calculator time:

![Mate Calc](assets/week11/mate_calc.jpg)

_mate_calc in programmer mode_
