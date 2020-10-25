class SevenSegment{

private:
  static void draw_horizontal(int pos_x, int pos_y, bool fill);
  static void draw_vertical(int pos_x, int pos_y, bool fill);
public:
  static void seven_segment_unit(int pos_x, int pos_y, bool *fill_list);

};
