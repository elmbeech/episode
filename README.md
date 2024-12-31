# episode

## installation

```bash
git clone https://github.com/elmbeech/episode.git
cd episode
make
./project
```

## changes compare to current PhysiCell version 1.14.1

1. PhysiCell `pull request 298` merged ( https://github.com/MathCancer/PhysiCell/pull/298 )
1. `main.cpp`  adapted to run multiple episodes
1. `custom_modules/custom.cpp` function `create_cell_types` morphed into function `generate_cell_types` and `reset_cell_types`.
1. `config/PhysiCell_settings.xml` morphed into `config/PhysiCell_settings_episode000.xml`, `config/PhysiCell_settings_episode001.xml`, `config/PhysiCell_settings_episode002.xml`.


## test flight
+ 2024-12-29: run 3 episodes, 7200 min, omp_num_threads 1, random_seed 0  => check for same output. ok.
+ 2024-12-29: run 3 episodes, 7200 min, omp_num_threads 16, random_seed 0 => check for different output. ok.
+ 2024-12-29: run 9 episodes, 7200 min, omp_num_threads 16, random_seed system_clock => check for different output. ok.
+ 2024-12-29: run 9 episodes, random max time between 1440 min and 10080 min (1 day and 7 days), omp_num_threads 16, random_seed system_clock => check for different output. ok.

SOMETIMES THE EPOCH WORKS FINE.
SOMETIMES THE EPOCH RUNS INTO A CORE DUMPED (always at delete cells: custom_modules/custom.cpp ~ line 72.

+ 20224-12-30: run 1024 episodes, random max time between 1440 min and 10080 min (1 day and 7 days), omp_num_threads 16, random_seed system_clock => no core dumped! ok.


## using the gnu debugger (on a linux)

Amazing blog post: https://askubuntu.com/questions/1349047/where-do-i-find-core-dump-files-and-how-do-i-view-and-analyze-the-backtrace-st

1. in the Make fiel add -ggdb -O0 flag to the compile command to generate a debug symbol table (-g optimized for gdb, code compiled with zero optimization) .

analyze a core dump
1. at the command line run `ulimit -c` to see the max dumpfile size
1. at the command line run `ulimit -c unlimited` on the terminal you run the code that dumps.
1. at `/var/log/apport.log` figure out the corde dumped file name.
1. at `/var/lib/apport/coredump/` is the file to find.
1. fire up gdb with executable and dumpfile like this: `gdb ./project /var/lib/apport/coredump/<filename>`

alternatively, run c++ executable inside gdb
1. gdb ./project
1. r  (run)
1. bt (back trace)
1. bt full (back trace)


## generating core dumps.

1. 2024-12-30: running custom.cpp `setup_microenvironment();` is NOT causing core dump.
1. 2024-12-30: running custom.cpp `setup_tissue();` can cause core dump (PhysiCell::add_PhysiCell_cells_to_open_xml_pugi_v2())!
1. 2024-12-30: running custom.cpp `reset_cell_types()d;` can cause core dump (BioFVM::Basic_Agent::release_internalized_substrates())!
1. 2024-12-30: running mani.cpp `create_cell_container_for_microenvironment(microenvironment, mechanics_voxel_size)` and custom.cpp `setup_microenvironment();` can causes the core dump!
1. 2024-12-30: at BioFVM/BioFVM_microenvironment.cpp add update_microenvironment parameter to initialize_microenvironment function solves the core get dumped  issue!

## notes
things i noticed and i am not sure if physicell is supposded to run like this.

1. random seed can nonly be set once. if set a second time (by relloading the xml file) we ge the waring.
```
WARNING: Setting the random seed again.
	You probably have set a user parameter called random_seed.
	Here, we will use the random seed set in user parameters.
	HOWEVER, as of PhysiCell 1.14.0, you should set the random seed in the <options><random_seed> element in the config file.
	Future versions of PhysiCell may throw an error here. Kindly remove the user parameter and just use the <options><random_seed> element.
```
