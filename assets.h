#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define ID_LEN     15
#define NAME_LEN   50
#define TEXT_LEN   30

void assetMenu(void);       /* Asset Management sub-menu           */
void addAsset(void);        /* Add a new asset                     */
void displayAssets(void);   /* Show all assets                     */
void searchAsset(void);     /* Search by ID or name                */
void assetReport(void);     /* Asset report (used by Reports menu) */

#endif