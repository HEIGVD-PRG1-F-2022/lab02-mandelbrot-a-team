//
// Created by Syra on 11.10.2022.
//

#include "util.h"

/**
 * Will normalize value between a new defined range
 * @param value the current value you want to match your new range
 * @param targetMin lowest limit of your new range
 * @param targetMax highest limit of your new range
 * @param currentMin lowest value possible of current value range
 * @param currentMax highest value possible of current value range
 * @return equivalent interpretation of the value in the specified new range
 */
int normalizeRange(int value, int targetMin, int targetMax, int currentMin, int currentMax) {

    return ((currentMax-value)*1.0-currentMin) / (1.0*currentMax - currentMin) * (1.0*targetMax-targetMin) + 1.0*targetMin;
}