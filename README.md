# episode

### installation

```bash
git clone https://github.com/elmbeech/episode.git
cd episode
make
./project
```

### changes compare to current PhysiCell version 1.14.1

1. PhysiCell `pull request 298` merged ( https://github.com/MathCancer/PhysiCell/pull/298 )
1. `main.cpp`  adapted to run multiple episodes
1. `custom_modules/custom.cpp` function `create_cell_types` morphed into function `generate_cell_types` and `reset_cell_types`.
1. `config/PhysiCell_settings.xml` morphed into `config/PhysiCell_settings_episode000.xml`, `config/PhysiCell_settings_episode001.xml`, `config/PhysiCell_settings_episode002.xml`.


### test flight
+ 2025-12-29: run 3 episodes, 7200 min, omp_num_threads 1, random_seed 0  => check for same output. ok.
+ 2025-12-29: run 3 episodes, 7200 min, omp_num_threads 16, random_seed 0 => check for different output. ok.
+ 2025-12-29: run 9 episodes, 7200 min, omp_num_threads 16, random_seed system_clock => check for different output. ok.
+ 2025-12-29: run 9 episodes, random max time between 1440 min and 10080 min (1 day and 7 days), omp_num_threads 16, random_seed system_clock => check for different output. ok.

SOMETIMES THE EPOCH WORKS FINE.
SOMETIMES THE EPOCH RUNS INTO A CORE DUMPED (always at delete cells: custom_modules/custom.cpp ~ line 72.


### using the gnu debugger (on a linux)
1. in the Make fiel add -ggdb -O0 (or -g) flag to the compile command (to generate a debug symbol table).
1. at the command line run `ulimit -c` to see the max dumpfile size
1. at the command line run `ulimit -c unlimited` befor every run you expect a core dump.
1. at `/var/log/apport.log` figure out the corde dumped file name.
1. at `/var/lib/apport/coredump/` is the file to find.
1. `gdb /var/lib/apport/coredump/<filename>`
