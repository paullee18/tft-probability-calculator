# TFT Probability Calculator
Welcome to this personal project of mine, a tool for helping me make optimal decisions when playing the game Teamfight Tactics (TFT).

## What is Teamfight Tactics (TFT)?
Teamfight Tactics is a strategy video game where you play against 7 other players. It has some similarities to poker and chess. 
You purchase units from your shop to play them against other players, these units are taken from a common pool shared amongst all 8 players.
Having played this game for a long time, I have always wondered how I could calculate probabilities to help me make informed decisions.

## How the probability calculation works
In this game, you have gold for you to spend. You can use your gold to see a shop, which shows you 5 shop slots, each with a unit you can purchase.
To determine which unit a shop slot contains, first it determines the tier of the unit. There are 5 unit tiers (1-5) and as you can imagine
, as your player level increases, the odds of getting higher tier units increases as well. After determining the unit tier, then it simply picks one
of the units from the tier randomly. For a particular unit, there are x copies in the pool, thus, the probability changes depending on
the copies already taken by other players or yourself.

The main question we want to solve is as follows: Given x amount of money, how likely am I to get at least y copies of a particular character?
One approach is to brute force the probability calculations, however, this is troublesome as the probability to get an additional copy decreases as we purchase more copies
since there will be fewer remaining. The alternative I discovered was to use Markov Chains! The states represent the number of copies I currently have, and in one shop slot
I can either go from state x to x+1 or remain at x. In code, this is modelled using transition matrices, where the (i,j)th entry represents the probability of going from
i copies to j copies in one shop slot. To handle x number of shop slots, we simply raise the matrix to the power of x to get the corresponding matrix.

## Design decisions
Proper OOP principles were used to encapsulate the various components of the project into different classes. Inheritance was used for easy extension of the project and for
easy testing, since mocks or stubs could be passed into objects. I made use of pthreads to parallelise matrix multiplication as I wanted to practice how to do so, although
it makes little practical sense in this project since our matrix size is fixed at 10x10.

## Things to add
- More comprehensive unit testing involving mocks.
- A frontend so that I can deploy this project for use by other players.
