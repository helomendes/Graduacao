# search.py
# ---------
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


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util
from game import Directions
from typing import List

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()




def tinyMazeSearch(problem: SearchProblem) -> List[Directions]:
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

def depthFirstSearch(problem: SearchProblem) -> List[Directions]:
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))
    """
    "*** YOUR CODE HERE ***"

    steps = util.Stack()
    path = []
    def dfs(problem, current, steps):
        if problem.isGoalState(current):
            return steps.list 
        path.append(current)
        successors = problem.getSuccessors(current)
        test = None
        for suc in successors:
            if suc[0] not in path:
                steps.push(suc[1])
                test = dfs(problem, suc[0], steps)
                if test:
                    break
        if not test and len(steps.list) > 0:
            steps.pop()
            return
        return steps.list
    return dfs(problem, problem.getStartState(), steps)
            
    util.raiseNotDefined()


def breadthFirstSearch(problem: SearchProblem) -> List[Directions]:
    """Search the shallowest nodes in the search tree first."""
    "*** YOUR CODE HERE ***"
    '''
    def bfs(problem, current, steps):
        if problem.isGoalState(current):
            return steps.list
        if current in path:
            return
        print('\nCurrent: ', current)
        path.append(current)
        while not neighbors.isEmpty():
            nex = neighbors.pop()
            temp.push(nex)
            print('Next: ', nex)
            bfs(problem, nex[0], steps)
        print('Temp: ', temp.list)
        
        while not temp.isEmpty():
            successors = problem.getSuccessors(temp.pop()[0])
            for successor in successors:
                neighbors.push(successor)

        bfs(problem, neighbors.pop()[0], steps)

    steps = util.Stack()
    neighbors = util.Queue()
    neighbors.push([problem.getStartState(), ''])
    temp = util.Queue()
    path = []
    return bfs(problem, problem.getStartState(), steps)
    util.raiseNotDefined()
    '''
    neighbors = util.Queue()
    path = set()

    start_state = problem.getStartState()
    neighbors.push((start_state, []))

    while not neighbors.isEmpty():
        state, path = neighbors.pop()
        if state in path:
            continue
        path.add(state)
        if problem.isGoalState(state):
            return path
        for successor, action, _ in problem.getSuccessors(state):
            if successor not in path:
                neighbors.push((successor, path + [action]))
    return []  

def uniformCostSearch(problem: SearchProblem) -> List[Directions]:
    """Search the node of least total cost first."""
    "*** YOUR CODE HERE ***"
    neighbors = util.Queue()
    util.raiseNotDefined()

def nullHeuristic(state, problem=None) -> float:
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem: SearchProblem, heuristic=nullHeuristic) -> List[Directions]:
    """Search the node that has the lowest combined cost and heuristic first."""
    "*** YOUR CODE HERE ***"
    util.raiseNotDefined()

# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
