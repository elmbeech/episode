////////
// title: PhyiCell/custom_modules/custom.h
//
// language: C++
// date: 2015-2024
// license: BSD-3-Clause
// author: Elmar Bucher, Paul Macklin
// original source code: https://github.com/MathCancer/PhysiCell
// modified source code: https://github.com/elmbeech/physicellembedding
////////


#include "../core/PhysiCell.h"
#include "../modules/PhysiCell_standard_modules.h"

using namespace BioFVM;
using namespace PhysiCell;

// setup functions to help us along
void random_seed(void);
void generate_cell_types(void);
void reload_cell_types(void);
void setup_tissue(void);

// set up the BioFVM microenvironment
void setup_microenvironment(bool update_variables = false);

// custom pathology coloring function
std::vector<std::string> my_coloring_function(Cell*);

// custom functions can go here
void phenotype_function(Cell* pCell, Phenotype& phenotype, double dt);
void custom_function(Cell* pCell, Phenotype& phenotype, double dt);
void contact_function(Cell* pMe, Phenotype& phenoMe, Cell* pOther, Phenotype& phenoOther, double dt);

