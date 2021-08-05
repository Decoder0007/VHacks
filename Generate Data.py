import os
import re

currentposition = int(input("Current Position:  "))
pattern="[A-Z]"

while True:
    namelower = input("Enter Name:  ")
    menuname = input("Menu:  ")
    nameupper = namelower[0].upper()+namelower[1:-1]+namelower[-1]
    namespaces = re.sub(pattern, lambda x:" "+x.group(0), nameupper)
    currentposition -= 30

    print()
    print("Paste the code below")
    print()
    
    print("---Layer.cpp---")
    print("auto "+namelower+"Button = gd::CCMenuItemToggler::create(("+namelower+"Enabled) ? toggleOn : toggleOff, ("+namelower+"Enabled) ? toggleOff : toggleOn, "+menuname+", menu_selector(Vhacks::Callbacks::"+nameupper+"Button));")
    print("auto "+namelower+"Text = CCLabelBMFont::create(\""+namespaces[1:-1]+namespaces[-1]+"\", \"bigFont-uhd.fnt\");")
    print(namelower+"Text->setTag(2);")
    print(namelower+"Button->setScale(0.8f);")
    print(namelower+"Text->setScale(0.5f);")
    print(namelower+"Button->setPositionX(0);")
    print(namelower+"Text->setPositionX(25 + ("+namelower+"Text->getScaledContentSize().width / 2));")
    print(namelower+"Button->setPositionY("+str(currentposition)+");")
    print(namelower+"Text->setPositionY("+str(currentposition)+");")
    print(""+menuname+"->addChild("+namelower+"Button);")
    print(""+menuname+"->addChild("+namelower+"Text);")
    print()

    print("---Layer.h---")
    print("void "+nameupper+"Button(CCObject*);")
    print()

    print("---HackBools.cpp---")
    print("bool "+namelower+"Enabled = false;")
    print()

    print("---HackBools.h---")
    print("extern bool "+namelower+"Enabled;")
    print()
    

    input("Press Enter")

    os.system("cls")
