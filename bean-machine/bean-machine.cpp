#include <iostream>

using namespace std;

constexpr int num_slots = 30;
constexpr int num_beans = 5000;

constexpr int to_left = 0;
constexpr int to_right = 1;

constexpr char left_symbol = 'L';
constexpr char right_symbol = 'R';
constexpr char bean_symbol = '*';

constexpr bool should_print_path = false;
constexpr int max_bucket_size = 80;

int main() {
	srand(time(0));
	int slots[num_slots];

	for (int i = 0; i < num_slots; i++) slots[i] = 0;

	for (int i = 0; i < num_beans; i++) {
		int pos = 0;
		for (int j = 0; j < num_slots - 1; j++) {
			int direction = rand() % 2;  // Adding 0 to the position is considered 
			                             // a move to the left because the number 
										 // positions on the next row grows
			pos += direction;
			if (should_print_path)
				if (direction == to_left) cout << left_symbol;
				else cout << right_symbol;
		}
		slots[pos]++;
		if (should_print_path) cout << '\n';
	}

	int max_slot_count = slots[0];
	for (int i = 0; i < num_slots; i++)
		if (slots[i] > max_slot_count) max_slot_count = slots[i];

	for (int i = 0; i < num_slots; i++) {
		cout << i << ": " << slots[i] << "\t\t";
		int normalized_count = slots[i] * max_bucket_size / max_slot_count;
		for (int j = 0; j < normalized_count; j++) cout << bean_symbol;
		if (0 < slots[i] && normalized_count == 0) cout << bean_symbol;
		cout << '\n';
	}

	cout << "\nBeans Dropped: " << num_beans << '\n';
}