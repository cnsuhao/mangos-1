UPDATE command SET `help` = 'Syntax: .learn #parameter\r\n\r\nSelected character learn a spell of id #parameter. A GM can use .learn all if he wants to learn all default spells for Game Masters, .learn all_lang to learn all langauges, and .learn all_myclass to learn all spells available for his class (Character selection in these cases ignored).' WHERE `name` = 'learn';
