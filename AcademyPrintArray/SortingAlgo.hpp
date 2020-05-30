#pragma once

#include "Player.hpp"

// Using int instead of uint32_t to implement the same signature as in the exercise instructions
// Using Player[] instead of Student[] because in page 3 of the instructions we have been asked to create Player class and not Student
// But overall they are the same - the naming is the only diffrence

int NaivePrint(Player players[], int n, int k);
int BSTPrint(Player players[], int n, int k);
int PrintBySort(Player players[], int n, int k);