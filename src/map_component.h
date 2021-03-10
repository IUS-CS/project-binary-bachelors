#ifndef MAP_COMPONENT_H
#define MAP_COMPONENT_H

struct MapComponent {
  MapComponent() {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 31; j++) {
        level[i][j] = 0;
      }
    }
  }
  MapComponent(int loaded_level[20][31]) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 31; j++) {
        level[i][j] = loaded_level[i][j];
      }
    }
  }
  int level[20][31];
};
#endif
