import { Row, Layout, Typography, Button } from 'antd';
import { HeatMapOutlined, PlusOutlined } from '@ant-design/icons';

const { Footer } = Layout;
const { Title, Paragraph } = Typography;

function _Footer(): any
{
    return(
        <>
            <Footer>
                <Row className='box'>
                    <Row>
                        <Title level={4}>
                            Let's Have a Fun!
                        </Title>
                        <Paragraph>
                            Like a nice party to this night? <br /> Let's Go!
                        </Paragraph>
                    </Row>
                    <Row className='icon'>
                        <HeatMapOutlined />
                    </Row>
                </Row>
            </Footer>
        </>
    );
}

export default _Footer;