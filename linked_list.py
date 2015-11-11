class Node:
    def __init__(self, value=None, next=None):
        self.__value = value
        self.__next = next
        return

    def set_value(self, value):
        self.__value = value
        return

    def get_value(self):
        return self.__value

    def set_next(self, nodeReference):
        self.__next = nodeReference
        return

    def get_next(self):
        return self.__next




class LinkedList:
    def __init__(self, listOfElements=[]):
        self.__root = None
        self.__length = 0
        if listOfElements:
            self.__root = Node(value=listOfElements[0])
            currentNode = self.__root
            for i in range(1,len(listOfElements)):
                newNode = Node(value=listOfElements[i])
                currentNode.set_next(newNode)
                currentNode = newNode
            self.__length = len(listOfElements)
        return




    def append(self, value):
        if self.__length == 0:
            newNode = Node(value=value)
            self.__root = newNode
        else:
            newNode = Node(value=value)
            endNode = self.__get_node_at_index(self.__length - 1)
            endNode.set_next(newNode)
        self.__length += 1
        return



    def prepend(self, value):
        if self.__length == 0:
            self.append(value)
        else:
            newNode = Node(value=value)
            newNode.set_next(self.__root)
            self.__root = newNode
        self.__length += 1
        return



    def insert(self, value, index):
        if index >= self.__length:
            print("You can't insert out of range you dunce!")
            return -1
        elif index == 0:
            self.prepend(value)
        elif index == self.__length:
            self.append(value)
        else:
            newNode = Node(value=value)
            previousNode = self.__get_node_at_index(index - 1)
            nextNode = self.__get_node_at_index(index)
            previousNode.set_next(newNode)
            newNode.set_next(nextNode)
            self.__length += 1
        return



    def delete(self, index):
        if index >= self.__length or index < 0:
            print("You can't delete elements out of range you dunce!")
            return -1
        elif index == 0:
            self.__root = self.__root.get_next()
        else:
            previousNode = self.__get_node_at_index(index - 1)
            nextNode = previousNode.get_next().get_next()
            previousNode.set_next(nextNode)
        self.__length -= 1
        return



    def remove(self, value):
        index = self.find(value)
        if index != -1:
            self.delete(index)
        else:
            print("You cannot delete a value that does not exist.")
        return



    def pop(self):
        toReturn = None
        if self.__length > 0:
            toReturn = self[self.__length - 1]
            self.delete(self.__length - 1)
        else:
            print("You cannot pop from an empty list.")
        return toReturn



    def reverse(self):
        if self.__length == 0 or self.__length == 1:
            return
        elif self.__length == 2:
            previousNode = self.__root
            previousNode.get_next().set_next(self.__root)
            self.__root.set_next(None)
            self.__root = previousNode
        else:
            previousNode = self.__root
            currentNode = self.__root.get_next()
            nextNode = currentNode.get_next()
            previousNode.set_next(None)
            for i in range(2, self.__length):
                currentNode.set_next(previousNode)
                previousNode = currentNode
                currentNode = nextNode
                nextNode = currentNode.get_next()
            currentNode.set_next(previousNode)
            self.__root = currentNode
        return




    def find(self, value):
        if self.__length == 0:
            print("You cannot search an empty list.")
            return -1
        found = False
        count = 0
        currentNode = self.__root
        while not found:
            if currentNode.get_value() == value:
                return count
            currentNode = currentNode.get_next()
            if currentNode.get_next() == None:
                found = True
            count += 1
        print("Value (" + str(value) + ") was not found in the list.", sep="")
        return -1



    def __getitem__(self, index):
        if index >= self.__length or index < 0:
            print("You can't access elements out of range you dunce!")
            return 
        return self.__get_node_at_index(index).get_value()



    def __len__(self):
        return self.__length



    def __str__(self):
        toReturn = "["
        for i in range(self.__length - 1):
            toReturn += str(self[i]) + ", "
        if self.__length > 0:
            toReturn += str(self[self.__length - 1]) + "]"
        else:
            toReturn += "]"
        return toReturn



    def __get_node_at_index(self, index):
        currentNode = self.__root
        count = 0
        while count != index:
            currentNode = currentNode.get_next()
            count += 1
        return currentNode

    def get_root(self):
        return self.__root
