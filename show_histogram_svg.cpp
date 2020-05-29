#include "show_histogram_svg.h"

    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;

string make_info_text() {
    stringstream buffer;
    DWORD info = GetVersion();
    DWORD mask = 0x0000ff00;
    int platform = info >> 16;
    int version_major = info & (mask>>8);
    int version_minor = (info & (mask))>>8;
    buffer << "<tspan>";
    buffer << "Windows v"<<version_major<<"."<<version_minor;
    //printf("Windows v%d.%d",version_major,version_minor);
    if((info&0x80000000)==0){
        int build = platform;
        buffer<<" (build "<<build<<")";
        //printf(" (build %d)",build);
    }
    buffer<<"\n </tspan> \n <tspan x='"<<TEXT_LEFT<<"' dy='1em'>";
    //printf("\n");
    char ComputerName[MAX_COMPUTERNAME_LENGTH+1];
    DWORD mcl = MAX_COMPUTERNAME_LENGTH;
    GetComputerNameA(ComputerName,&mcl);
    //printf("%s\n",ComputerName);
    buffer<<"Computer name: "<<ComputerName<<"\n </tspan> \n";
    return buffer.str();
}
void show_histogram_svg(const vector<size_t>& bins)
{
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;
    for (size_t bin : bins)
    {
        const double bin_width = BLOCK_WIDTH * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        //svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "#ffeeee");
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
        top += BIN_HEIGHT;
    }
    svg_text(TEXT_LEFT, top + TEXT_BASELINE,make_info_text());
    svg_end();
}
