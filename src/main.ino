#include <Button.h>

const int channel = 1;

Button button1 = Button(2, INPUT_PULLUP);
Button button2 = Button(7, INPUT_PULLUP);
Button button3 = Button(12, INPUT_PULLUP);
Button button4 = Button(14, INPUT_PULLUP);
Button button5 = Button(18, INPUT_PULLUP);
Button button6 = Button(23, INPUT_PULLUP);

Button buttons[6] = { button1, button2, button3, button4, button5, button6 };

void setup() {
}

void loop() {
	for (int i = 0; i < 6; i++) {
		if (buttons[i].uniquePress()) usbMIDI.sendNoteOn(i, 64, channel);
		else if (buttons[i].stateChanged() && !buttons[i].isPressed()) usbMIDI.sendNoteOn(i + 6, 64, channel);
	}
	delay(200);
	// MIDI Controllers should discard incoming MIDI messages.
	while (usbMIDI.read()) {
	}
}
