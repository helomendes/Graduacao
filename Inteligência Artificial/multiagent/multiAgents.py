# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent
from pacman import GameState

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState: GameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState: GameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        "*** YOUR CODE HERE ***"

        currentFood = currentGameState.getFood()
        cur_food = sum(1 for row in currentFood for item in row if item)
        new_food = sum(1 for row in newFood for item in row if item)

        foods = newFood.asList()
        foodsDist = [manhattanDistance(f, newPos) for f in foods]

        ghostPosition = successorGameState.getGhostPositions()
        ghostDist = [manhattanDistance(g, newPos) for g in ghostPosition]

        capsules = currentGameState.getCapsules()
        newCapsules = successorGameState.getCapsules()
        capsDist = [manhattanDistance(c, newPos) for c in newCapsules]

        cur_caps = len(capsules)
        new_caps = len(newCapsules)

        score = successorGameState.getScore()

        scaredBonus = 0
        for idx, value in enumerate(ghostDist):
            if newScaredTimes[idx] == 0 and value < 2:
                return -(float("inf"))
            elif newScaredTimes[idx] > 0:
                scaredBonus += 2000/(value + 1)

        foodPoints = 0
        if foodsDist:
            foodPoints += 1000/(sum(foodsDist) + 1)
            foodPoints += 5000/(len(foodsDist) + 1)

        eatenPoints = 0
        if cur_food > new_food:
            eatenPoints = 3000

        capsulePoints = 0
        if capsDist:
            capsulePoints += 2000/(sum(capsDist) + 1)
            capsulePoints += 3000/(len(capsDist) + 1)

        capsuleBonus = 0
        if cur_caps > new_caps:
            capsuleBonus = 5000

        points = score + foodPoints + eatenPoints + capsulePoints + scaredBonus + capsuleBonus
        return points

def scoreEvaluationFunction(currentGameState: GameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (question 2)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
        "*** YOUR CODE HERE ***"

        def minimax(agentIndex, depth, state):
            if state.isWin() or state.isLose() or depth == self.depth:
                return self.evaluationFunction(state)

            numAgents = state.getNumAgents()
            legalActs = state.getLegalActions(agentIndex)
            if not legalActs:
                return self.evaluationFunction(self)

            if agentIndex == 0:
                bestValue = float('-inf')
                for act in legalActs:
                    suc = state.generateSuccessor(agentIndex, act)
                    value = minimax(1, depth, suc)
                    bestValue = max(bestValue, value)
                return bestValue
            else:
                nextAgent = (agentIndex + 1) % numAgents
                if nextAgent == 0:
                    nextDepth = depth + 1
                else:
                    nextDepth = depth
                bestValue = float('inf')
                for act in legalActs:
                    suc = state.generateSuccessor(agentIndex, act)
                    value = minimax(nextAgent, nextDepth, suc)
                    bestValue = min(bestValue, value)
                return bestValue

        bestScore = float('-inf')
        bestAct = None
        for act in gameState.getLegalActions(0):
            suc = gameState.generateSuccessor(0, act)
            value = minimax(1, 0, suc)
            if value > bestScore:
                bestScore = value
                bestAct = act

        return bestAct

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        def alphabeta(agentIndex, depth, state, alpha, beta):
            if state.isWin() or state.isLose() or depth == self.depth:
                return self.evaluationFunction(state)

            nextAgent = (agentIndex + 1) % state.getNumAgents()
            if nextAgent == 0:
                nextDepth = depth + 1
            else:
                nextDepth = depth
            legalActs = state.getLegalActions(agentIndex)
            if not legalActs:
                return self.evaluationFunction(self)

            if agentIndex == 0:
                value = float('-inf')
                for act in legalActs:
                    suc = state.generateSuccessor(agentIndex, act)
                    value = max(value, alphabeta(nextAgent, nextDepth, suc, alpha, beta))
                    if value > beta:
                        return value 
                    alpha = max(alpha, value)
                return value
            else:
                value = float('inf')
                for act in legalActs:
                    suc = state.generateSuccessor(agentIndex, act)
                    value = min(value, alphabeta(nextAgent, nextDepth, suc, alpha, beta))
                    if value < alpha:
                        return value
                    beta = min(beta, value)
                return value

        bestScore = float('-inf')
        bestAct = None
        alpha = float('-inf')
        beta = float('inf')
        for act in gameState.getLegalActions(0):
            suc = gameState.generateSuccessor(0, act)
            value = alphabeta(1, 0, suc, alpha, beta)
            if value > bestScore:
                bestScore = value
                bestAct = act
            alpha = max(alpha, bestScore)

        return bestAct

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        "*** YOUR CODE HERE ***"
        def expectimax(agentIndex, depth, state):
            if state.isWin() or state.isLose() or depth == self.depth:
                return self.evaluationFunction(state)

            nextAgent = (agentIndex + 1) % state.getNumAgents()
            if nextAgent == 0:
                nextDepth = depth + 1
            else:
                nextDepth = depth
            legalActs = state.getLegalActions(agentIndex)
            if not legalActs:
                return self.evaluationFunction(state)

            if agentIndex == 0:
                expect = []
                for act in legalActs:
                    suc = state.generateSuccessor(agentIndex, act)
                    expect.append(expectimax(nextAgent, nextDepth, suc))
                return max(expect)
            else:
                values = []
                for act in legalActs:
                    suc = state.generateSuccessor(agentIndex, act)
                    values.append(expectimax(nextAgent, nextDepth, suc))
                return sum(values)/len(values)

        bestScore = float('-inf')
        bestact = None
        for act in gameState.getLegalActions(0):
            successor = gameState.generateSuccessor(0, act)
            value = expectimax(1, 0, successor)
            if value > bestScore:
                bestScore = value
                bestact = act

        return bestact


def betterEvaluationFunction(currentGameState: GameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: ganha pontos ao se aproximar da comida, perde pontos ao se aproximar dos fantasmas porém ganha pontos ao se aproximar deles quando estão com medo, ganha pontos ao comer as power pellets. Perde pontos por ainda existirem comida e power pellets no mapa.
    """
    "*** YOUR CODE HERE ***"
    if currentGameState.isWin():
        return float('inf')
    if currentGameState.isLose():
        return float('-inf')

    curPos = currentGameState.getPacmanPosition()
    curFoods = currentGameState.getFood().asList()
    curGhostStates = currentGameState.getGhostStates()
    curCapsules = currentGameState.getCapsules()
    points = currentGameState.getScore()

    foodsDist = [manhattanDistance(f, curPos) for f in curFoods]
    ghostDist = [manhattanDistance(g.getPosition(), curPos) for g in curGhostStates]
    scaredTimes = [g.scaredTimer for g in curGhostStates]

    if foodsDist:
        points += 10.0/min(foodsDist)

    for idx, ghostd in enumerate(ghostDist):
        if scaredTimes[idx] > 0:
            points += 20.0/max(ghostd, 1)
        else:
            if ghostd <= 1:
                points -= 1000
            else:
                points -= 2.0/ghostd

    if curCapsules:
        capsDist = [manhattanDistance(caps, curPos) for caps in curCapsules]
        points += 10.0/min(capsDist)

    points -= 4*len(curFoods)
    points -= 15*len(curCapsules)

    return points

# Abbreviation
better = betterEvaluationFunction
