from argparse import ArgumentParser
import os.path

from pyvirtualdisplay import Display
display = Display (visible = 0, size = (1024, 768), use_xauth = True)
display.start ()
import os
os.environ ["DISPLAY"] = ":" + str(display.display) + "." + str(0)

import pyautogui
import time


def is_valid_file(parser, arg):
    if not os.path.exists(arg):
        parser.error(f"The file {arg} does not exist!")
    else:
        return open(arg, 'r')  # return an open file handle


parser = ArgumentParser(description="Write file content on cursor")

parser.add_argument("-f", dest="filename", required=True,
                    help="input file containing the code", metavar="FILE",
                    type=lambda x: is_valid_file(parser, x))

parser.add_argument("-d", dest="delay", required=True,
                    help="Delay in sec before writing to the cursor", type=int)


args = parser.parse_args()

print(f"Writing to cursor in {args.delay} sec...")
time.sleep(args.delay)

file_content = args.filename.read()

pyautogui.write(file_content, interval= 0.05)
