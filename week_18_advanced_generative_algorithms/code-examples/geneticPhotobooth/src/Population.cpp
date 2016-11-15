#include "Population.h"
#include <algorithm>

static bool compare(Individual i, Individual j) {
     return (i.fitness<j.fitness);
}
//-------------------------------------------------------
Population::Population() {
    topPercentileToKeep = 0.15;
}
//-------------------------------------------------------
void Population::setup(ofImage _target, float m, int num)
{
    target = _target;
    mutationRate = m;
    population.clear();

    for (int x=0; x<num; x++){
        Individual individual;
        individual.setup(300); //300 genes = 300 triangles
        population.push_back(individual);
    }
    calcFitness();
    hasFinished = false;
    generations = 0;
    perfectScore = 0; // perfect score = no pixel difference
}
//------------------------------------------------------------
// Calculate the fitness of every individual in the population
void Population::calcFitness() {
    for (int i = 0; i < population.size(); i++) {
      population[i].getFitness(target);
    }
}

//------------------------------------------------------------
// Generate a mating pool
void Population::naturalSelection() {
    // Clear the vector
    matingPool.clear();
    sort(population.begin(), population.end(), compare);

    int numOfTopIndividuals = population.size() * topPercentileToKeep;

    for (int i = 0; i < numOfTopIndividuals; i++) {
           matingPool.push_back(population[i]);
    }
}
//------------------------------------------------------------
// Create a new generation
void Population::generate() {
    // Refill the population with children from the mating pool
    for (int i = 0; i < population.size(); i++) {
      int a = int(ofRandom(matingPool.size()));
      int b = int(ofRandom(matingPool.size()));
      Individual partnerA = matingPool[a];
      Individual partnerB = matingPool[b];
      DNA childDNA = partnerA.dna.crossover(partnerB.dna);
      childDNA.mutate(mutationRate);
      Individual child;
      child.setup(childDNA);
      population[i] = child;
    }
    generations++;
}
//------------------------------------------------------------
// Compute the current "most fit" member of the population
ofImage Population::getBest() {
    float worldrecord = 255.0f;
    int index = 0;

    for (int i = 0; i < population.size(); i++) {
      if (population[i].fitness < worldrecord) {
        index = i;
        worldrecord = population[i].fitness;
      }
    }
    if (worldrecord == perfectScore ) hasFinished = true;
    return population[index].getPhenotype(320, 240);
  }
//------------------------------------------------------------
bool Population::finished() {
    return hasFinished;
  }
//------------------------------------------------------------
int Population::getGenerations() {
    return generations;
  }
//------------------------------------------------------------
// Compute average fitness for the population
float Population::getAverageFitness() {
    float total = 0;
    for (int i = 0; i < population.size(); i++) {
      total += population[i].fitness;
    }
    return total / population.size();
}
