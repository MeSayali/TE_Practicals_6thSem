# Simple Conversational Railway Chatbot

print("🤖 Railway Chatbot Started!")
print("Type 'exit' to stop the chatbot.\n")

while True:
    user_input = input("You: ").lower()

    if user_input in ["hi", "hello", "hey"]:
        print("Bot: Hello! How can I help you today?")

    elif "help" in user_input:
        print("Bot: I can help you with booking tickets, cancelling tickets, or checking price.")

    elif "book" in user_input:
        name = input("Bot: Enter your name: ")
        source = input("Bot: Enter source station: ")
        destination = input("Bot: Enter destination station: ")
        seats = input("Bot: Number of seats: ")
        print(f"Bot: Ticket booked successfully for {name} from {source} to {destination}.")

    elif "cancel" in user_input:
        name = input("Bot: Enter your name to cancel ticket: ")
        print(f"Bot: Ticket cancelled successfully for {name}.")

    elif "price" in user_input:
        distance = int(input("Bot: Enter distance in km: "))
        price = distance * 2
        print(f"Bot: Estimated ticket price is ₹{price}")

    elif user_input == "exit":
        print("Bot: Thank you! Have a safe journey.")
        break

    else:
        print("Bot: Sorry, I didn't understand. Type 'help' to know what I can do.")