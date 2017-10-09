from abc import ABCMeta, abstractmethod

class Tree(metaclass=ABCMeta):
    """Abstract class representing a tree structure."""

    class NodePosition(metaclass=ABCMeta):
        """Represents position of a given node in the tree."""

        @abstractmethod
        def element(self):
            """Return the element stored at this NodePosition."""
            raise NotImplementedError
        
        @abstractmethod
        def __eq__(self, other):
            """
               Return True if other NodePosition 
               represents the same location.
            """
            raise NotImplementedError

        @abstractmethod
        def __ne__(self, other):
            """
               Return True if other NodePosition does
               not represent the same location.
            """
            return not (self == other)
        
    @abstractmethod
    def root(self):
        """
           Return NodePosition representing the 
           tree`s root (None if empty).
        """
        raise NotImplementedError

    @abstractmethod
    def parent(self, node_position):
        """
           Return NodePosition representing
           node_position`s parent.
        """
        raise NotImplementedError

    @abstractmethod
    def children_count(self, node_position):
        """Return count of children that NodePosition node_position has."""
        raise NotImplementedError

    @abstractmethod
    def children(self, node_position):
        """
           Return generator over NodePosition
           node_position children.
        """
        raise NotImplementedError

    @abstractmethod
    def __len__(self):
        """Return the number of elements in the three."""
        raise NotImplementedError

    def is_root(self, node_position):
        """
           Return True if NodePosition node_position
           represents the root of the tree.
        """
        return self.root() == node_position

    def is_leaf(self, node_position):
        """Return True if NodePosition node_position is leaf."""
        return self.num_children(node_position) == 0

    def is_empty(self, node_position):
        """Return True if the tree is empty."""
        return len(self) == 0

    def depth(self, node_position):
        """
           Return NodePosition node_position`s
           depth in the tree.
        """
        if self.is_root(node_position):
            return 0
        else:
            return 1 + self.depth(self.parent(node_position))

    def _height1(self):
        """
           Return the height of the tree. 
           -O(n^2) worst case, where n is
           the size of the subtree.
        """
        return max(self.depth(p) for p in self.positions() if self.is_leaf(p))

    def _height2(self, p):
        """
           Return the height of the subtree
           rooted at NodePosition p.
           -O(n) worst case, where n is
           the size of the subtree.
        """
        if self.is_leaf(p):
            return 0
        else:
            return 1 + max(self._height2(c) for c in self.children(p))

    def height(self, p=None):
        """Return the height of the subtree rooted at NodePosition p.
        
        If p is None, return the height of the entire tree.
        """
        if p is None:
            p = self.root()
        return self._height2(p)
        
