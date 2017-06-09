#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

bool FuzzMe(const uint8_t *Data,
            size_t DataSize) {
  return DataSize >= 3 &&
      Data[0] == 'F' &&
      Data[1] == 'U' &&
      Data[2] == 'Z' &&
      Data[3] == 'Z';  // :‑<
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  printf("FuzzMe: %d\n", FuzzMe(Data, Size));
  return 0;
}

int main(int argc, char *argv[]) {
  uint8_t buf[4];
  read(STDIN_FILENO, buf, 4);
  LLVMFuzzerTestOneInput(buf, 4);
}
