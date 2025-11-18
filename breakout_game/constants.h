#ifndef CONSTANTS_H
#define CONSTANTS_H

struct constants {
  static constexpr int window_width{800};
  static constexpr int window_height{800};
  static constexpr int ball_size{25};
  static constexpr float ball_speed{6.0f};
  static constexpr int brick_rows{4};
  static constexpr int brick_columns{8};
  static constexpr float brick_width{80.0f};
  static constexpr float brick_height{40.0f};
  static constexpr int brick_strength{3};
  static constexpr float paddle_width{100.0f};
  static constexpr float paddle_height{20.0f};
  static constexpr float paddle_speed{10.0f};
  
};

#endif // CONSTANTS_H
