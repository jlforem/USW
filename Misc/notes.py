def double_string(input_string):
    return ''.join([char * 2 for char in input_string])

# Example usage
example_input = "hello world"
print(double_string(example_input))  # Output: hheelllloo  wwoorrlldd

def merge(dict1, dict2):
    merged_dict = dict1.copy()
    merged_dict.update(dict2)
    return merged_dict

def total_score(score_dict):
    return sum(score_dict.values())

# Example usage
first_half = {"player1": 10, "player2": 15}
second_half = {"player2": 5, "player3": 20}
merged_scores = merge(first_half, second_half)
print(merged_scores)  # Output: {'player1': 10, 'player2': 5, 'player3': 20}
print(total_score(merged_scores))  # Output: 35

item_prices = {
    "sword": 100,
    "shield": 150,
    "potion": 50,
    "armor": 200,
    "boots": 75
}


# Example usage
items_purchased = ["sword", "potion", "boots"]
pinned_list = ["sword", "shield", "potion"]
unpurchased_items, receipt, total = calculate_total(items_purchased, pinned_list)
print(unpurchased_items)  # Output: ['shield']
print(receipt)  # Output: {'sword': 100, 'potion': 50, 'boots': 75}
print(total)  # Output: 225