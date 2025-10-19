import time
import speech_recognition as sr

class Robot:
    """Simulates the robot's hardware and core movements."""
    def __init__(self):
        self.name = "Smart Assistant Bot"
        print(f"{self.name} is online and awaiting voice commands... 🤖")

    def move_forward(self):
        print("Action: Moving forward...")

    def stop(self):
        print("Action: Stopping motors.")

    def turn(self, direction):
        print(f"Action: Turning {direction}...")
        time.sleep(0.5)

def listen_for_command():
    """Listens for a command and converts it to text."""
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("\nAdjusting for ambient noise, please wait...")
        recognizer.adjust_for_ambient_noise(source, duration=1)
        print("Listening for your command... 🎤")
        
        try:
            audio = recognizer.listen(source, timeout=5, phrase_time_limit=5)
            command = recognizer.recognize_google(audio)
            print(f"I heard you say: '{command}'")
            return command.lower()
        except sr.WaitTimeoutError:
            print("Listening timed out.")
            return None
        except sr.UnknownValueError:
            print("Sorry, I could not understand.")
            return None
        except sr.RequestError as e:
            print(f"Service error; {e}")
            return None

def run_voice_controlled_robot():
    """Main function to run the robot's loop."""
    my_robot = Robot()

    while True:
        command = listen_for_command()

        if command:
            if "forward" in command or "go" in command:
                my_robot.move_forward()
            elif "stop" in command or "hold" in command:
                my_robot.stop()
            elif "left" in command:
                my_robot.turn("left")
            elif "right" in command:
                my_robot.turn("right")
            elif "exit" in command or "quit" in command or "shutdown" in command:
                print("Shutdown command received. Goodbye! 👋")
                break
            else:
                print("Command not recognized. Please try 'forward', 'stop', 'left', 'right', or 'exit'.")

if __name__ == "__main__":
    run_voice_controlled_robot()
