# Source Code: https://stackoverflow.com/questions/62314497/access-of-outer-environment-variable-in-platformio
# Script to grab sensitive data (variables) from .env file

from os.path import isfile
Import("env")
assert isfile(".env")
try:
  f = open(".env", "r")
  lines = f.readlines()
  envs = []
  for line in lines:
    envs.append("-D{}".format(line.strip()))
  env.Append(BUILD_FLAGS=envs)
except IOError:
  print("File .env not accessible",)
finally:
  f.close()
