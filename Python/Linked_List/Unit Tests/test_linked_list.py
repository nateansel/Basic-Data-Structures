import unittest
from linked_list import *
 
class TestLinkedList(unittest.TestCase):
    def setUp(self):
        self.tempNode = Node()
        return



    def test_LinkedList_append(self):
        testList = LinkedList()
        testList.append(5)
        self.assertEqual(testList[0], 5)
        return



    def test_LinkdList_prepend(self):
        testList = LinkedList()
        testList.append(5)
        testList.prepend(4)
        self.assertEqual(testList[0], 4)
        return



    def test_LinkedList_insert(self):
        testList = LinkedList()
        testList.append(1)
        testList.append(3)
        testList.insert(value=2, index=1)
        self.assertEqual([testList[0],testList[1],testList[2]], [1,2,3])
        return



    def test_LinkedList_delete(self):
        testList = LinkedList([1,2,3])
        testList.delete(1)
        self.assertEqual([testList[0],testList[1]], [1,3])
        return



    def test_LinkedList_remove(self):
        testList = LinkedList([1,2,3])
        testList.remove(2)
        self.assertEqual([testList[0], testList[1]], [1,3])
        return



    def test_LinkedList_pop(self):
        testList = LinkedList([1,2,3])
        popped = testList.pop()
        self.assertEqual(popped, 3)
        return



    def test_LinkedList_reverse(self):
        testList = LinkedList([1,2,3,4,5])
        testList.reverse()
        self.assertEqual([testList[0],testList[1],testList[2],testList[3],testList[4]], [5,4,3,2,1])
        return



    def test_LinkedList_str(self):
        testList = LinkedList([1,2,3,4,5])
        self.assertEqual(str(testList),"[1, 2, 3, 4, 5]")
        return
        



    # def test_custom_LinkedList(self):
    #     pass
 


if __name__ == '__main__':
    unittest.main()
