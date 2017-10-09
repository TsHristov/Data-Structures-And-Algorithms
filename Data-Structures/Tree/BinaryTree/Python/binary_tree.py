import sys
sys.insert(0, '../../Python')
import tree


class BinaryTree(tree.Tree):
    """Abstract class representing a binary tree structure."""

    @abstractmethod
    def left(self, position):
        """Return NodePosition representing position`s left child.
 
        Return None if position does not have a left child.
        """
        raise NotImplementedError

    @abstractmethod
    def right(self, position):
        """Return NodePosition representing position`s right child.

        Return None if position does not have a right child.
        """
        raise NotImplementedError


    def sibling(self, position):
        """Return NodePosition representing position`s sibling.
       
        Return None if no there is no sibling.
        """
        parent = self.parent(position)
        if not parent:
            return None
        elif position == self.left(parent):
            # Return the right child:
            return self.right(parent)
        elif position == self.right(parent):
            # Return the left child:
            return self.left(parent)

    def children(self, position):
        """Generate an iteration of NodePositions representing
           position`s children.
        """
        if self.left(position):
            yield self.left(position)
        if self.right(position):
            yield self.right(position)
