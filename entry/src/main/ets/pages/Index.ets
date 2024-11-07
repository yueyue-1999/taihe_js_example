import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            // test int
            hilog.info(0x0000, 'testTag', 'Test NAPI Sub 3 - 2 = %{public}d', testNapi.sub(3, 2));

            // test str
            let as = testNapi.split_str("apple", 2);
            hilog.info(0x0000, 'testTag', 'Test NAPI split_str apple at 2, get %{public}s and %{public}s', as[0], as[1]);

            // test rgb
            let rgb : testNapi.RGB = testNapi.get_rgb(0xff << 0o20);
            hilog.info(0x0000, 'testTag', 'Test NAPI get_rgb, r: %{public}d, g: %{public}d, b: %{public}d', rgb.r, rgb.g, rgb.b);

            let rgb2 = new testNapi.RGB()
            hilog.info(0x0000, 'testTag', 'Test NAPI get_rgb2, r: %{public}d, g: %{public}d, b: %{public}d', rgb2.r, rgb2.g, rgb2.b);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
