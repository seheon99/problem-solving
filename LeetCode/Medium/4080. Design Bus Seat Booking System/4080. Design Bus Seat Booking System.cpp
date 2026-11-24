
class BusBooking {
private:
    vector<array<int, 4>> cost;
    int totalTime = 0;
    int bookedCount = 0;

public:
    BusBooking(int n) {
        cost.resize(n + 1, {0, 0, 0, 0});
    }

    void toggle(string seat) {
        int col = seat[0] - 'A';
        int row = stoi(seat.substr(1));

        if (cost[row][col] != 0) {
            totalTime -= cost[row][col];
            cost[row][col] = 0;
            bookedCount--;
            return;
        }

        int time = 1;
        if (col == 0 && cost[row][1] != 0) {
            time += 2;
        }
        if (col == 3 && cost[row][2] != 0) {
            time += 2;
        }

        cost[row][col] = time;
        totalTime += time;
        bookedCount++;
    }

    int getTotalTime() {
        return totalTime;
    }

    int getMinTime() {
        return bookedCount;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */