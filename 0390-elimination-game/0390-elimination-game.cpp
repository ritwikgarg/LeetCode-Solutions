class Solution {
public:
    int lastRemaining(int n) {
        int direction = 1; // 1 -> l to r, -1 -> r to l

        return lastNumber(n, direction, 1, 1, n);
    }

    int lastNumber(int n, int direction, int first, int step, int remaining) {
            if (remaining == 1) {
                return first;
            }
            
            if (direction == 1 || ((direction == -1) && (remaining % 2 == 1))) {
                first+=step;
            }

            return lastNumber(n, direction*-1, first ,step*2, remaining/2);
    }
};