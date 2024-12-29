# episode

### installation

```bash
git clone https://github.com/elmbeech/episode.git
cd episode
make
./project
```

### changes compare to current PhysiCell versuon 1.14.1

1. PhysiCell `pull request 298` merged ( https://github.com/MathCancer/PhysiCell/pull/298 )
1. `main.cpp`  adapted to run multiple episodes
1. `custom_modules/custom.cpp` function `create_cell_types` morphed into function `generate_cell_types` and `reset_cell_types`.
1. `config/PhysiCell_settings.xml` morphed into `config/PhysiCell_settings_episode000.xml`, `config/PhysiCell_settings_episode001.xml`, `config/PhysiCell_settings_episode002.xml`.



### tested ###
+ 2025-12-29: run 3 episodes, 7200 min, omp_num_threads 1, random_seed 0  => check for same output. ok.
+ 2025-12-29: run 3 episodes, 7200 min, omp_num_threads 16, random_seed 0 => check for different output. ok.
+ 2025-12-29: run 3 episodes, 7200 min, omp_num_threads 16, random_seed system_clock => check for different output. ok.

