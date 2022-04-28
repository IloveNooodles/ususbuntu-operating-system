#include "header/filesystem.h"
#include "header/std_type.h"
#include "header/textio.h"
#include "header/fileio.h"
#include "header/program.h"
#include "header/utils.h"

int main(){
  struct message m;
  struct node_filesystem node_fs_buffer;
  int i;
  int cur_idx = 0xFF;
  getMessage(&m, getCurrentSegment());

  cur_idx = m.current_directory;
  interrupt(0x21, 0x2, &(node_fs_buffer.nodes[0]), FS_NODE_SECTOR_NUMBER, 0);
  interrupt(0x21, 0x2, &(node_fs_buffer.nodes[32]), FS_NODE_SECTOR_NUMBER + 1, 0);

  if(m.arg2[0] == '\0'){
    return;
  } else if(m.arg2[0] == '/'){
    
  }

}

void cd(byte *parentIndex, char *dir, enum fs_retcode *ret_code) {  
  if(dir[0] == '\0'){
    *ret_code = FS_R_NODE_NOT_FOUND;
    return;
  } else if(dir[0] == '/'){
    *parentIndex = read_relative_path(FS_NODE_P_IDX_ROOT, dir + 1, ret_code);
    return;

  } else {
    *parentIndex = read_relative_path(*parentIndex, dir, ret_code);
  }
}